from math import factorial as f

n = int(input())

def b(n, k):
	return f(n)//f(k)//f(n-k)
	
print(b(n, 5)**2*120)