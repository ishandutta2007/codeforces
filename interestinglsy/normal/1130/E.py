import sys
try:
	sys.stdin = open('in.in','r')
	sys.stdout = open('out.out','w')
except: pass

k = int(input())

print(2000)
k += 2000
print(-1,end=' ')
for i in range(1999):
	if not k: print(0,end=' ')
	else:
		if k <= 1000000:
			print(k,end=' ')
			k = 0
		else:
			print(1000000,end=' ')
			k -= 1000000