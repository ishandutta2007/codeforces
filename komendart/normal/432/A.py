n, k = [int(i) for i in input().split()]
L = len([int(i) for i in input().split() if int(i) + k <= 5])
print(L//3)