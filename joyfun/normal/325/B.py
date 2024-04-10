f=n=int(input())
N=1
while N<=n*2:
 l,h=0,n
 while h>=l:
  m=(l+h)//2
  r=(m*2+1)*(m+N-1)
  if r>n:h=m-1
  elif r<n:l=m+1
  else:
   print(m*2*N+N)
   f=0
   break
 N*=2
if f:print(-1)