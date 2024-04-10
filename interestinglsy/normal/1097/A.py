import sys
def OK(a,b):
	return a[0] == b[0] or a[1] == b[1]

ss = input().strip()
for i in input().strip().split():
	if OK(ss,i):
		print('YES')
		sys.exit(0)
print('NO')