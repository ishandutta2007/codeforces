n,m=map(int,input().split())
x,y,M=0,1,10**9+7
while n>0:
	x,y,n=(2*m*x-x+y)%M,y*m%M,n-1
print((y+m*x)%M)