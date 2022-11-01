t = int(input())
for ti in range(t):
	n,x,a,b = map(int,input().split())
	ans = min( n-1 , abs(b-a)+x )
	print(ans)