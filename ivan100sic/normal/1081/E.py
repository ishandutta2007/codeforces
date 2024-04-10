import math
n=int(input())
a=list(map(int,input().split()))
r=lambda y:int(math.sqrt(y))
def R(x):
 y=r(x)
 return y*y==x
z=0
b=[]
for i in a:
 f=0
 for q in range(r(z)+1,3160000):
  y=q*q-z;
  if R(q*q+i):
   b+=[y,i];z+=i+y;f=1;break
 if f<1:
  print('No');exit(0)
print('Yes\n',*b)