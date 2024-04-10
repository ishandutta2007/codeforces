import sys

t = int(input())
for _ in range(t):
	n = int(input())
	A = [int(x) for x in input().split()]
	i = 0
	j = len(A) - 1
	a_tot = 0
	b_tot = 0
	move = 0
	alice = 0
	bob = 0
	while i <= j:
		move += 1
		alice = 0
		while i <= j and alice <= bob:
			alice += A[i]
			i += 1
		if i <= j:
			move += 1
		bob = 0
		while i <= j and alice >= bob:
			bob += A[j]
			j -= 1
		a_tot += alice
		b_tot += bob
	print(move, a_tot, b_tot)