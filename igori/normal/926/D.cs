using System;
class Program
{
    static void Main()
    {
        string[] str = new string[6];
        var t = 0;
        for (var i = 0; i < 6; i++)
            str[i] = Console.ReadLine();
        if (str[0][3] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 0 && j == 3)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[0][4] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 0 && j == 4)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[1][3] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 1 && j == 3)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[1][4] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 1 && j == 4)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[0][0] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 0 && j == 0)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[0][1] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 0 && j == 1)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[1][0] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 1 && j == 0)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[1][1] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 1 && j == 1)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[0][6] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 0 && j == 6)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[0][7] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 0 && j == 7)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[1][6] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 1 && j == 6)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[1][7] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 1 && j == 7)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[2][3] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 2 && j == 3)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[2][4] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 2 && j == 4)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[3][3] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 3 && j == 3)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[3][4] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 3 && j == 4)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[2][0] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 2 && j == 0)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[2][1] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 2 && j == 1)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[3][0] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 3 && j == 0)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[3][1] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 3 && j == 1)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[2][6] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 2 && j == 6)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[2][7] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 2 && j == 7)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[3][6] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 3 && j == 6)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[3][7] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 3 && j == 7)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[4][3] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 4 && j == 3)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[4][4] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 4 && j == 4)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[5][3] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 5 && j == 3)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[5][4] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 5 && j == 4)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[4][0] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 4 && j == 0)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[4][1] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 4 && j == 1)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[4][6] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 4 && j == 6)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[4][7] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 4 && j == 7)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[5][0] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 5 && j == 0)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[5][1] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 5 && j == 1)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[5][6] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 5 && j == 6)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
        if (str[5][7] == '.' && t == 0)
        {
            for (var i = 0; i < 6; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i == 5 && j == 7)
                    Console.Write("P");
                    else
                    Console.Write(str[i][j]);
                }
                Console.WriteLine("");
            }
            t = 1;
        }
    }

}