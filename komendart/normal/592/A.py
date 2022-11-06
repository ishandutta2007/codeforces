board = [input() for i in range(8)]
A = B = 1000
for i in range(8):
    for j in range(8):
        if board[j][i] == 'B':
            break
        if board[j][i] == 'W':
            A = min(A, j)
    for j in range(8):
        if board[7 - j][i] == 'W':
            break
        if board[7 - j][i] == 'B':
            B = min(B, j)

if A <= B:
    print('A')
else:
    print('B')