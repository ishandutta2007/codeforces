
# Iterative Python 3 program to find 
# modular inverse using extended 
# Euclid algorithm 
  
# Returns modulo inverse of a with 
# respect to m using extended Euclid 
# Algorithm Assumption: a and m are 
# coprimes, i.e., gcd(a, m) = 1 
def modInverse(a, m) : 
    m0 = m 
    y = 0
    x = 1
  
    if (m == 1) : 
        return 0
  
    while (a > 1) : 
  
        # q is quotient 
        q = a // m 
  
        t = m 
  
        # m is remainder now, process 
        # same as Euclid's algo 
        m = a % m 
        a = t 
        t = y 
  
        # Update x and y 
        y = x - q * y 
        x = t 
  
  
    # Make x positive 
    if (x < 0) : 
        x = x + m0 
  
    return x 

n = int(input())

mod = 998244353
out = []

fac = [1]
big = [1]
for i in range(1, n+10):
    fac.append((fac[-1]*i)%mod)
    big.append((10*big[-1])%mod)


for i in range(1, n+1):
    if i == n:
        out.append('10')
    elif i == n-1:
        out.append('180')
    else:
        num = n-i
        blah = 2*(big[num] - big[num-1])
        blah %= mod
        blah += (n-i-1)*(big[num] - 2*big[num-1] + big[num-2])
        blah %= mod
        blah *= 10
        blah %= mod
        out.append(str(blah))
print(' '.join(out))