def main():
    n = int(input()[-2:])
    result = (1 + 2 ** ((n - 1) % 4 + 1) +
            3 ** ((n - 1) % 4 + 1) + 4 ** ((n - 1) % 2 + 1)) % 5
    print(result)


main()