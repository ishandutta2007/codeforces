n, m = [int(i) for i in input().split()]
d = [input() for i in range(n)]

result = 0
for i in range(n - 1):
    for j in range(m - 1):
        if sorted(d[i][j] + d[i + 1][j] + d[i][j + 1] + d[i + 1][j + 1]) == sorted(list("face")):
            result += 1

print(result)