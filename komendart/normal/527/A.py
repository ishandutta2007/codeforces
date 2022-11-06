a, b = [int(i) for i in input().split()]
a, b = min(a, b), max(a, b)

result = 0
while a != b:
    a, b = min(a, b), max(a, b) 
    result += (b - 1) // a
    b -= (b - 1) // a * a
    
print(result + 1)