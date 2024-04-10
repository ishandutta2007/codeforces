n,m,a,b=map(int,input().split())
s=0
if n%m>0:
	s=min(n%m*b,(m-n%m)*a)
print(s)