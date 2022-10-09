n,m=map(int,input().split())
if n+m<3:
	print(0);exit(0)
a=max(n, m)+2
b=min(n, m)
c=list(range(2,a))
d=[1]+list(range(a,a+b-1))
if n<m:
	c,d=d,c
for i in c:
	print(*[x*i for x in d])