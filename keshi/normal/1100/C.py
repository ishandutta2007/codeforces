from math import*
n,r=map(int,input().split())
x=((n-2)*180)/n/2
x=cos(radians(x))
print((x*r)/(1-x))