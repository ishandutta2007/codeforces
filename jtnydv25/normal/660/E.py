n,m = map(int,raw_input().split())
md = 10**9 + 7
if m == 1:
	print n + 1
else:
	print ((pow(m,n,md) + m*(pow(2*m-1,n,md)-pow(m,n,md))*pow(m-1,md-2,md))%md + md)%md