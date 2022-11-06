n, m = [int(i) for i in input().split()]
energy = [int(i) for i in input().split()]
result = 0
for i in range(m):
    x, y = [int(i) for i in input().split()]
    result += min(energy[x - 1], energy[y - 1])
        
print(result)