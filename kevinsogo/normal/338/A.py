mod = 10**9 + 9

def f(n,m,k):
	s = 0
	w = m-n+n/k
	if w > 0:
		n -= w * k
		m -= w * k
		s = 2*(pow(2,w,mod)-1)*k
	return (s + m)%mod

from sys import *

n, m, k = map(int, raw_input().strip().split())

print f(n,m,k)