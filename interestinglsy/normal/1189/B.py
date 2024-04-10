n = int(input())
a = list(map(int,input().split()))
a.sort()

if a[-2]+a[-3] <= a[-1]:
	print('NO')
else:
	print('YES')
	print(a[-2],a[-1],end=' ')
	for i in range(n-3,-1,-1):
		print(a[i],end=' ')
	print()