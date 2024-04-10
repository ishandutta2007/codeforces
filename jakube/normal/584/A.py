def read_numbers():
    return list(map(int, input().split()))

n, t = read_numbers()

upper_limit = eval("9"*n)
number = (upper_limit // t) * t

if len(str(number)) == n and number > 0:
    print(number)
else:
    print(-1)