import sys,os

def Solve(n,k):
	if n == k or n == 1 or n == 2: return 1
	if n == 0: return 0
	if k > n or k%3 != 0: return n%3 != 0
	# k is a 'win' point
	# n%3 != 0: win
	# n%3 == 0: lose
	return (n%(k+1))%3 != 0 or n%(k+1) == k

t = int(input())
for i in range(t):
	n,k = map(int,input().split())
	print( 'Alice' if Solve(n,k) else 'Bob' )