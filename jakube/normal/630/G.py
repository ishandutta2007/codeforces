from math import factorial as f

n = int(input())

def b(n, k):
	return f(n)//f(k)//f(n-k)
	
s5 = n
if (n > 1):
	s5 += n*(n-1)*2
	if (n > 2):
		s5 += n*(n-1)*(n-2)//2*2
		if (n > 3):
			s5 += n*(n-1)*(n-2)*(n-3)//f(3)
			if (n > 4):
				s5 += n*(n-1)*(n-2)*(n-3)*(n-4)//f(5)
		
s3 = n
if (n > 1):
	s3 += n*(n-1)
	if (n > 2):
		s3 += n*(n-1)*(n-2)//6
		
#print(s5, s3)
print(s5*s3)