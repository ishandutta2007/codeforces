n, m, k, l = map(int, input().split())
k += l
x = (k + m - 1) // (m);
if m * x > n:
    print(-1)
else:
    print(x)