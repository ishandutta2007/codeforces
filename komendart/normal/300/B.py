n, m = [int(i) for i in input().split()]

students = {i: -1 for i in range(1, n + 1)}
teams = []

have_solution = True
for i in range(m):
    a, b = [int(i) for i in input().split()]
    if students[a] == -1 and students[b] == -1:
        teams.append(set([a, b]))
        students[a] = students[b] = len(teams) - 1
    elif students[a] != -1 and students[b] != -1 and students[a] != students[b]:
        have_solution = False
        break
    else:
        students[a] = students[b] = max(students[a], students[b])
        teams[students[a]].add(a)
        teams[students[a]].add(b)
        if len(teams[students[a]]) > 3:
            have_solution = False
            break

if not have_solution:
    print(-1)
else:
    result = ""
    not_teams = []
    for key, value in students.items():
        if value == -1:
            not_teams.append(key)
    for i in teams:
        tmp = list(i)
        if len(i) != 3:
            if not_teams:
                tmp.append(not_teams.pop())
            else:
                have_solution = False
                break
        tmp.sort()
        result += ' '.join(str(j) for j in tmp)
        result += '\n'
    while not_teams:
        result += ' '.join(str(not_teams.pop()) for j in range(3))
        result += '\n'
    if have_solution:
        print(result)
    else:
        print(-1)