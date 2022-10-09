def f(x):
 p=1;
 for i in range(1,x):
  p*=i
 return p
n,m,k=map(int,input().split())
print(m*(m-1)**k*f(n)//f(k+1)//f(n-k)%998244353)