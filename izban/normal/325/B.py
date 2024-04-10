from sys import *
import math

def sqr(x):
    return x * x

def Sqrt(x):
    l = 0
    r = 2 ** 150
    while (r - l > 1):
        m = (l + r) // 2
        if (m * m < x): l = m
        else: r = m
    if (r * r <= x): return r
    else: return l

fi = stdin
fo = stdout

n = int(fi.readline())

ans = []
o = 1
while (o <= 2 ** 100):
    d = sqr(2 * o - 3) + 8 * n
    if (d >= 0):
        sd = Sqrt(d)
        #fo.write(str(d) + " " + str(sd) + " " + str(sd * sd) + "\n")
        #fo.write(str(abs(sd * sd - d)) + "\n")
        if (d == sd * sd):
            if (-(2 * o - 3) + sd) % 2 == 0:
                x1 = (-(2 * o - 3) + sd) // 2
                x2 = (-(2 * o - 3) - sd) // 2
                if (x1 > 0) and (x1 % 2 == 1): ans.append(o * x1)
                if (x2 > 0) and (x2 % 2 == 1): ans.append(o * x2)
    o = o * 2        
    

f = 0
for x in sorted(ans):
    fo.write(str(x) + "\n")
    f = 1
    
if (f == 0):
    fo.write("-1\n")