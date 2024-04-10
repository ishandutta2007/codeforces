n = int(input())

a = 3*4**(2*n-2-n-1)
b = 9*4**(2*n-2-n-2)

print(int(2*a + b*(n-3))*4)