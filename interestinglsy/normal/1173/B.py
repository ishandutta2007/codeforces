n = int(input())

m = 1
while 2*(m-1)+1 < n: m += 1
print(m)
for i in range(1,m+1):
	print(1,i)
	n -= 1
	if not n:
		break
if n:
	for i in range(2,m+1):
		print(i,m)
		n -= 1
		if not n: break