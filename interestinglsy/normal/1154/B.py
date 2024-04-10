import sys

def FILEIO():
	try: sys.stdin = open('in.in','r')
	except: pass
FILEIO()

def End(x):
	print(x)
	sys.exit()

input()
a = list(map(int,input().split()))
a = list(set(a))
a.sort()

if len(a) > 3: End(-1)
if len(a) == 3:
	if a[2]-a[1] != a[1]-a[0]: End(-1)
	End(a[2]-a[1])
if len(a) == 2:
	if (a[1]-a[0])%2 == 0: End((a[1]-a[0])//2)
	End(a[1]-a[0])
End(0)
###