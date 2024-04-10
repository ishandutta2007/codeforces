def exponent(n, p):
	ret, n = 0, n / p
	while n : ret, n = ret + n, n / p
	return ret
def n0(n) : return exponent(n, 5)	
m, ans, s = input(), 0, ""
for i in range(1, 1000000):
	r =  n0(i)
	if r > m: break
	if r == m: ans, s = ans + 1, s + str(i) + " "
print ans	
if ans: print s