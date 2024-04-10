_in = input().split()
n = int(_in[0])
k = int(_in[1])

if (n+1)//2 >= k:
    print(2*k - 1)
else:
    print(2*(k -( (n+1)//2)))