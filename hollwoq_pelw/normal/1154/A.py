a = sorted([int(k) for k in input().split(' ')])
b = [a[3]-a[i] for i in range(3)]
print(*b)