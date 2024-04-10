import sys
try:
	sys.stdin = open('in.in','r')
	sys.stdout = open('out.out','w')
except: pass

n,m = map(int,input().split())

def Len(st,ed):
	st += 1
	ed += 1
	if st <= ed: return ed-st
	else: return ed+n-st

cnt = [ 0 for i in range(n) ]
mxlen = [ n+233 for i in range(n) ]
for i in range(m):
	a,b = map(int,input().split())
	a -= 1; b -= 1
	cnt[a] += 1
	mxlen[a] = min( mxlen[a] , Len(a,b) )

for st in range(n):
	ans = 0
	for i in range(n):
		if not cnt[i]: continue
		tans = Len(st,i) + (cnt[i]-1)*n + mxlen[i]
		ans = max(ans,tans)
	print(ans,end=' ')