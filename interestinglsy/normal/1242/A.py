import os, sys, math

n = int(input())
sqt = int(math.sqrt(n))

def IsPrime(n):
	for i in range(2,sqt+1):
		if n%i == 0:
			return False
	return True
if IsPrime(n):
	print(n)
	sys.exit(0)

found = 0
for i in range(2,sqt+1):
	if n%i != 0: continue
	x = n/i
	while x%i == 0:
		x /= i
	if x == 1:
		print(i)
		sys.exit(0)
	else:
		found += 1
		if found == 2:
			print(1)
			sys.exit(0)
print(1)