def psi(x):
	x=[9-int(i) for i in str(x)]
	s=""
	for i in x: s += str(i)
	return int(s)
	
l,r=[int(i) for i in raw_input().split()]
p=int("4"+"9"*(len(str(r))-1))
if p <= r and p >= l:
	print p*psi(p)
else:
	print max(r*psi(r), l*psi(l))