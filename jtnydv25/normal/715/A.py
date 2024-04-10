from math import *
n = input()
l = 2
num = 2
for k in range(1,n+1):
    r = k*(k+1)*(k+1) - l
    l = k
    print r