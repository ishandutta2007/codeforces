H, N = [int(i) for i in input().split()]

result = 0
side = 0
for h in range(H, 0, -1):
    result += 1
    if side ^ (N > 1 << (h - 1)):
        result += (1 << h) - 1
    else:
        side ^= 1
    if N > 1 << (h - 1):
        N -= 1 << (h - 1)
    
print(result)