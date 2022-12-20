n, m = map(int, input().split())

def validate(matrix):
    # rows
    for row in matrix:
        for i in range(len(row)-1):
            if row[i] >= row[i+1]:
                return False
    # cols
    for i in range(m):
        for j in range(n-1):
            if matrix[j][i] >= matrix[j+1][i]:
                return False
    return True

a = [[int(val) for val in input().split()] for _ in range(n)]
b = [[int(val) for val in input().split()] for _ in range(n)]
for i in range(n):
    for j in range(m):
        a[i][j], b[i][j] = min(a[i][j], b[i][j]), max(a[i][j], b[i][j])
if validate(a) and validate(b):
    print("Possible")
else:
    print("Impossible")