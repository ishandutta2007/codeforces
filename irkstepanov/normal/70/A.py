x = int(input())
if x == 0:
    print(1)
else:
    print((3 ** (x - 1)) % (1000003))