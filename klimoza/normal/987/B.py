n, m = map(int, input().split())
pow_1 = m
pow_2 = n
while(pow_1 > 1 or pow_2 > 1):
    pow_1 /= 2
    pow_2 /= 2
if(n == m):
    print("=")
else:
    n = pow(n, pow_1)
    m = pow(m, pow_2)
    if(n > m):
        print(">")
    elif(n < m):
        print("<")
    else:
        print("=")