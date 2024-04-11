T,A,B=map(int,raw_input().strip().split(" "))

def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a%b)

if A>B:
	A,B=B,A

G=gcd(A,B)
L=A*B/G

tie = (T/L)*A
tie += min(A-1,(T%L))

g=gcd(tie,T)
print "%d/%d" % (tie/g,T/g)