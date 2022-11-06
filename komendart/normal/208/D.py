n = int(input())
p = [int(i) for i in input().split()]
cost = [int(i) for i in input().split()]

result = [0 for i in range(5)]
points = 0

for i in p:
    points += i
    for i in range(4, -1, -1):
        result[i] += points // cost[i]
        points = points % cost[i]

print(' '.join(str(i) for i in result))
print(points)