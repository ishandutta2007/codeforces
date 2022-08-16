import sys
n = input()
if n < 3:
    print -1
    sys.exit()
if not n&1:
    x= n/2
    print x**2-1, x**2 + 1
    sys.exit()
b = (1+n)/2
a = (n-1)/2
print 2*a*b, a**2+b**2