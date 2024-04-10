import sys
try:
	sys.stdin = open('in.in','r')
	sys.stdout = open('out.out','w')
except: pass

n = int(input())
a = list(map(int,input().split()))
a.sort()
suma = sum(a)

ans = 9999999999999999999999999
for i in range(n):
	cur = a[i]
	for j in range(1,cur+1):
		if cur%j != 0: continue
		minx = a[0] if i != 0 else a[1]
		tsum = suma - a[i] - minx + a[i]//j + minx*j
		ans = min(ans,tsum)

print(ans)