n, m = map(int, input().split())
arr = ['' for i in range(n)]
for i in range(n):
    arr[i] = input()
k = 0
s = 200
for i in range(n):
    for j in range(m):
        if arr[i][j] == 'B':
            s = min(j, s)
            k += 1
    if k != 0:
        print(i + 1 + k // 2, s + 1 + k // 2)
        break