from math import gcd
from sys import stdout
from random import randrange
n = int(input())
vals = [n]
def S(x):
    for i in range(n):
        if i*i%n == x:
            return i
    return -1
for i in range(15):
    A = randrange(0, n)
    B = A*A%n

    print("sqrt", B)
    stdout.flush()
    B = int(input())
    A = (A+B)%n
    nvals = []
    for i in vals:
        x = gcd(A, i)
        y = i//x
        if x != 1:
            nvals.append(x)
        if y != 1:
            nvals.append(y)
    vals = nvals
    if len(vals) == 0:
        vals = [n]
print("!", len(vals), " ".join(str(i) for i in vals))