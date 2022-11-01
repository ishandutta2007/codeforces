import sys

a = list(map(int,input().split()))
a.sort()

x,y,z,w = a
print( (x+z-y)//2 , (x+y-z)//2 , (y+z-x)//2 )