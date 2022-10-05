import math
import random

N=int(input())

S=set()
S.add(N)
for i in range(40):
	x = random.randint(1,N-1)
	print("sqrt %d" % (x*x%N))
	y = int(input())
	
	a = (x+y)%N
	
	T=set()
	for s in S:
		T.add(math.gcd(s,a))
		T.add(s//math.gcd(s,a))
	S=T

S-={1}
S=list(S)
print("! %d %s" % (len(S), " ".join([str(x) for x in S])))