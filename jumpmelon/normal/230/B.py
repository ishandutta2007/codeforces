# Eratosthenes 
m = 10**6
IsPrime = [True for i in range(m + 1)]
for x in range(2, m + 1):
    if IsPrime[x]:
        for t in range(x * x, m + 1, x):
            IsPrime[t] = False
IsPrime[1] = False

# main
from math import sqrt
n = int(input())
A = list(map(int, input().split()))
for x in A:
    y = int(sqrt(x))
    if y * y == x and IsPrime[y]:
        print('YES')
    else:
        print('NO')