n = int(input())
ar = input().split()
max = 0
for i in ar:
    t = 0
    for j in i:
        if j.upper() == j:
            t += 1
    if t > max:
        max = t
print(max)