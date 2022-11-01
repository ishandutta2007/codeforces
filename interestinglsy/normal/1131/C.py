import sys
try:
	sys.stdin = open('in.in','r')
	sys.stdout = open('out.out','w')
except: pass

def Print(a):
	for i in a: print(i,end=' ')

n = int(input())
a = list(map(int,input().split()))
a.sort()

e = []
o = []
for i in range(n):
	if i%2 == 0: e.append(a[i])
	else: o.append(a[i])
e.reverse()
Print(o)
Print(e)