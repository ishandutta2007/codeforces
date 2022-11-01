import sys
try:
	sys.stdin = open('in.in','r')
	sys.stdout = open('out.out','w')
except: pass

n = int(input())
stx,sty = map(int,input().split())
stx -= 1; sty -= 1
edx,edy = map(int,input().split())
edx -= 1; edy -= 1
a = []
for i in range(n):
	a.append(input())

dsu = [ i for i in range(n*n+2) ]
def Findfa(pos):
	if dsu[pos]==pos: return pos
	dsu[pos] = Findfa(dsu[pos])
	return dsu[pos]
def Unite(a,b):
	a = Findfa(a)
	b = Findfa(b)
	dsu[a] = b

ids = []
nowid = 0
for i in range(n):
	tid = []
	for j in range(n):
		nowid += 1
		tid.append(nowid)
	ids.append(tid)
# print(ids)

for i in range(n):
	for j in range(n):
		if i != 0 and a[i-1][j] == a[i][j] == '0':
			Unite(ids[i-1][j],ids[i][j])
		if j != 0 and a[i][j-1] == a[i][j] == '0':
			Unite(ids[i][j-1],ids[i][j])

ans = 10000000000
stfa = Findfa(ids[stx][sty])
edfa = Findfa(ids[edx][edy])
if stfa == edfa:
	print(0)
	exit(0)
for i in range(n):
	for j in range(n):
		if Findfa(ids[i][j]) != stfa: continue
		for k in range(n):
			for l in range(n):
				if Findfa(ids[k][l]) != edfa: continue
				ans = min( ans , (k-i)*(k-i) + (l-j)*(l-j) )
print(ans)