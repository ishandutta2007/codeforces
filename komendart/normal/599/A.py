a, b, c = [int(i) for i in input().split()]
print(min(2 * (a + b), 2 * (a + c), 2 * (b + c), a + b + c))