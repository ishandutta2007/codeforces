import sys
R=range
I=sys.stdout.flush
J=input
def f(l,r):
 print('?',l,r);I();J()
 print('?',l,r);I();return int(J())
n,t=map(int,J().split())
a=[0]*(n+1)
w=[0]*(n+1)
def F(l,r):
 for i in R(1,r+1):
  a[i]^=1;w[i]^=1
 for i in R(l,n+1):
  a[i]^=1;w[i]^=1
def D(x,l,r):
 global t
 T=t
 while 1>0:
  t=f(l,r)
  if t!=T:
   F(l,r);break
 K=[0,0]
 for i in R(1,n+1):
  if(i<l or i>r)and i!=x:
   K[a[i]]+=1
 L,K=K
 a[x]=(1-K+L+t-T)//2
def P():
 S=""
 for i in R(1,n+1):
  S+=str(a[i]^w[i])
 print('!',S);I();exit(0)
if n<2:
 a[1]=t;P()
D(1,2,n)
D(n,1,n-1)
if n==2:
 P()
if n==3:
 a[2]=t-a[1]-a[3];P()
for i in R(2,n-1):
 D(i,i+1,n-1+i%2)
if n>2:
 a[n-1]=t-sum(a)-a[n-1];P()