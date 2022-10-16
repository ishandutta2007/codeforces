#!/usr/bin/python3
n, k = input().split()
n = int(n)
k = int(k)
if k % 2 == 0:
	print ('YES')
	print ('.' * n)
	print ('.' + '#' * (k // 2) + '.' * (n - 1 - k // 2))
	print ('.' + '#' * (k // 2) + '.' * (n - 1 - k // 2))
	print ('.' * n)
elif k % 2 == 1 and k <= n - 2:
	print ('YES')
	print ('.' * n)
	print ('.' * ((n - k) // 2) + '#' * k + '.' * ((n - k) // 2))
	print ('.' * n)
	print ('.' * n)
else:
	print ('YES')
	k -= (n - 2)
	print ('.' * n)
	print ('.' + '#' * (n - 2) + '.')
	print ('.' + '#' * (k // 2) + '.' * (n - 2 - k) + '#' * (k // 2) + '.')
	print ('.' * n)