def read_numbers():
    return list(map(int, input().split()))


def f(dim, track):
    #determine the possible starts
    possible = [i[0]=="s" for i in track]


    for i in range(1,dim[0],3):
        #first move the hero:
        new_possible = [False, False, False]

        if (possible[0] and track[0][i] == '.') or \
           (possible[1] and track[1][i] == '.' == track[0][i]):
            new_possible[0] = True

        if (possible[0] and track[0][i] == '.' == track[1][i]) or \
           (possible[1] and track[1][i] == '.') or \
           (possible[2] and track[2][i] == '.' == track[1][i]):
            new_possible[1] = True

        if (possible[1] and track[1][i] == '.' == track[2][i]) or \
           (possible[2] and track[2][i] == '.'):
            new_possible[2] = True

        possible = new_possible

        # new the trains:
        for j in range(i+1, min(i+3, dim[0])):
            possible = [possible[k] and track[k][j] == '.' for k in range(3)]

    return 'YES' if any(possible) else 'NO'


if __name__ == '__main__':
    n = int(input())
    for _ in range(n):
        dim = read_numbers()
        track = [input() for _ in range(3)]
        print(f(dim,track))