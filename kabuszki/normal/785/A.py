n = int(input())
res = 0
dick = {
    'T' : 4,
    'C' : 6,
    'O' : 8,
    'D' : 12,
    'I' : 20
}
for i in range(n):
    res += dick[input()[0]]
print(res)