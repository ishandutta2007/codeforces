n1, n2, k1, k2 = [int(i) for i in input().split()]

d = [[[0, 0] for i in range(n2 + 1)] for j in range(n1 + 1)]

for i in range(n1 + 1):
    for j in range(n2 + 1):
        if i == 0:
            d[i][j][0] = 0
            d[i][j][1] = 1
        elif j == 0:
            d[i][j][0] = 1
            d[i][j][1] = 0
        else:
            for k in range(max(0, i - k1), i):
                d[i][j][0] |= d[k][j][1] ^ 1
            for k in range(max(0, j - k2), j):
                d[i][j][1] |= d[i][k][0] ^ 1

if d[n1][n2][0]:
    print("First")
else:
    print("Second")