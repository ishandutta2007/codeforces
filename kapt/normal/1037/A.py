from math import log2 as l
n = int(input())
k = 2 ** int(l(n)) - 1
if k == n:
    print(int(l(n)))
else:
    print(int(l(n) + 1))